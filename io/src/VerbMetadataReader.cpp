
#include "model/VerbConjModel.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

#include <string>
#include <stdexcept>
#include <optional>
#include <fstream>

template <typename T>
T parsePrimitiveField(const rapidjson::Value& field, const std::string& name) {
    if (!field.Is<T>() && (!std::is_floating_point_v<T> || !field.Is<int>())) {
        throw std::runtime_error("Cannot parse " + name + " field: encountered a wrong type.");
    }
    return field.Get<T>();
}



template <typename T>
static std::optional<T> parsePrimitiveMember(const rapidjson::Value& parent, const std::string& field) {
    rapidjson::Value::ConstMemberIterator itr = parent.FindMember(field);
    if (itr != parent.MemberEnd()) {
        return parsePrimitiveField<T>(itr->value, field);
    }
    return std::nullopt;
}



// VerbConjModel readMetadata(const std::string& metadataPath) {
//     std::ifstream ifs(metadataPath);
//     if (!ifs.is_open()) {
//         throw std::runtime_error("File does not exist: " + metadataPath);
//     }

//     rapidjson::IStreamWrapper isw(ifs);
//     rapidjson::Document jsonSidecar;
//     jsonSidecar.ParseStream(isw);
//     if (!jsonSidecar.IsObject()) {
//         throw std::runtime_error("Syntax error in file: " + metadataPath);
//     }

//     VerbConjModel model;

//     // Parsing file object
//     rapidjson::Value::ConstMemberIterator itr = jsonSidecar.FindMember("file");
//     if (itr != jsonSidecar.MemberEnd() && itr->value.IsObject()) {
//         const rapidjson::Value& jsonFile = itr->value;
//     }
//     return model;
// }
