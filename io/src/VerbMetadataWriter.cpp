#include "model/VerbConjModel.h"
#include "rapidjson/document.h"
#include "rapidjson/ostreamwrapper.h"
#include "rapidjson/prettywriter.h"

#include <fstream>
#include <string>


static void fillFormData(const VerbConjModel::VerbFormData &data, rapidjson::Value& form, rapidjson::Document::AllocatorType& allocator){
    form.AddMember("变形", rapidjson::StringRef(data.formData), allocator);
    form.AddMember("例句", rapidjson::StringRef(data.exampleJap), allocator);
    form.AddMember("翻译", rapidjson::StringRef(data.translation), allocator);

}

void writeMetadata(const VerbConjModel& model, const std::string& outputPath) {

    rapidjson::Document verbList;
    verbList.SetArray();
    rapidjson::Document::AllocatorType& allocator = verbList.GetAllocator();

    rapidjson::Value forms(rapidjson::kArrayType);
    rapidjson::Value naiForm(rapidjson::kObjectType);
    rapidjson::Value naiFormData(rapidjson::kObjectType);
    fillFormData(model.naiForm, naiFormData, allocator);
    naiForm.AddMember(rapidjson::StringRef(model.naiForm.name), naiFormData, allocator);
    forms.PushBack(naiForm, allocator);

    rapidjson::Value masuForm(rapidjson::kObjectType);
    rapidjson::Value masuFormData(rapidjson::kObjectType);
    fillFormData(model.masuForm, masuFormData, allocator);
    masuForm.AddMember(rapidjson::StringRef(model.masuForm.name), masuFormData, allocator);
    forms.PushBack(masuForm, allocator);

    // fillFormData(model.dictForm, form, allocator);
    // form.AddMember(rapidjson::StringRef(model.dictForm.name), form, allocator);
    // forms.PushBack(form, allocator);

    // fillFormData(model.subForm, form, allocator);
    // form.AddMember(rapidjson::StringRef(model.subForm.name), form, allocator);
    // forms.PushBack(form, allocator);

    // fillFormData(model.condForm, form, allocator);
    // form.AddMember(rapidjson::StringRef(model.condForm.name), form, allocator);
    // forms.PushBack(form, allocator);

    // fillFormData(model.orderForm, form, allocator);
    // form.AddMember(rapidjson::StringRef(model.orderForm.name), form, allocator);
    // forms.PushBack(form, allocator);

    // fillFormData(model.desireForm, form, allocator);
    // form.AddMember(rapidjson::StringRef(model.desireForm.name), form, allocator);
    // forms.PushBack(form, allocator);

    // fillFormData(model.teForm, form,  allocator);
    // form.AddMember(rapidjson::StringRef(model.teForm.name), form, allocator);
    // forms.PushBack(form, allocator);

    // fillFormData(model.taForm, form, allocator);
    // form.AddMember(rapidjson::StringRef(model.taForm.name), form, allocator);
    // forms.PushBack(form, allocator);

    rapidjson::Value verb(rapidjson::kObjectType);
    verb.AddMember(rapidjson::StringRef(model.name), forms, allocator);

    verbList.PushBack(verb, allocator);

    std::ofstream ofs(outputPath);
    rapidjson::OStreamWrapper osw(ofs);

    rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(osw);
    verbList.Accept(writer);

}
