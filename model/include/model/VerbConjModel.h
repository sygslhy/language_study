#pragma once

#include <string>

struct VerbConjModel{
    struct VerbFormData{
        std::string name;
        std::string formData;
        std::string exampleJap;
        std::string translation;
    };

    std::string name;

    VerbFormData naiForm;
    VerbFormData masuForm;
    VerbFormData dictForm;
    VerbFormData subForm;
    VerbFormData condForm;
    VerbFormData orderForm;
    VerbFormData desireForm;
    VerbFormData teForm;
    VerbFormData taForm;
};
