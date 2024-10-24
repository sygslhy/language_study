#pragma once

#include <string>
#include <map>

struct VerbFormData{
    std::string formData;
    std::string exampleJap;
    std::string translation;
};

typedef std::map<std::string, VerbFormData> VerbConj;

class VerbConjModel {

public:

    class Builder;
    std::string getName() const {return name;}
    bool existForm(const std::string& name) const {return mData.find(name) == mData.end();}
    VerbFormData getForm(const std::string& name) const {
        return mData.at(name);
    }
    VerbConj getForms() const {return mData;}
private:
    std::string name;
    VerbConj mData;
    VerbConjModel() = default;

};

class VerbConjModel::Builder {

public:
    Builder& setName(const std::string& name){
        mModel.name = name;
        return *this;
    }

    Builder& setForm(const std::string& name,const std::string& form, const std::string& example, const std::string& translation){
        mModel.mData[name] = VerbFormData{form, example, translation};
        return *this;
    }

    VerbConjModel build() const{
        return VerbConjModel(mModel);
    }


private:
    VerbConjModel mModel;
};
