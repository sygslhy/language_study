#include "model/VerbConjModel.h"
#include "rapidjson/document.h"
#include "rapidjson/ostreamwrapper.h"
#include "rapidjson/prettywriter.h"

#include <fstream>
#include <string>

void writeMetadata(const VerbConjModel& model, const std::string& outputPath) {

    rapidjson::Document sidecar;
    sidecar.SetObject();
    rapidjson::Document::AllocatorType& allocator = sidecar.GetAllocator();

    rapidjson::Value verbs(rapidjson::kArrayType);
    VerbConj verbForms = model.getForms();
    rapidjson::Value forms(rapidjson::kArrayType);

    for(const auto& [key, value] : verbForms){
        rapidjson::Value form(rapidjson::kObjectType);
        rapidjson::Value formData(rapidjson::kObjectType);
        formData.AddMember("form", rapidjson::StringRef(value.formData), allocator);
        formData.AddMember("example", rapidjson::StringRef(value.exampleJap), allocator);
        formData.AddMember("translation", rapidjson::StringRef(value.translation), allocator);
        form.AddMember(rapidjson::StringRef(key), formData, allocator);
        forms.PushBack(form, allocator);
    }

    rapidjson::Value verb(rapidjson::kObjectType);
    verb.AddMember(rapidjson::StringRef(model.getName()), forms, allocator);

    std::ofstream ofs(outputPath);
    rapidjson::OStreamWrapper osw(ofs);

    rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(osw);
    sidecar.Accept(writer);

}
