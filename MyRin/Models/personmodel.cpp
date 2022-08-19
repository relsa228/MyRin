#include "personmodel.h"

QX_REGISTER_CPP_MYRIN(PersonModel)

PersonModel::PersonModel()
{

}

namespace qx {
template <> void register_class(QxClass<PersonModel> & t)
{
    t.id(&PersonModel::id, "id");

    t.data(&PersonModel::FirstName, "FirstName");
    t.data(&PersonModel::Surname, "Surname");
    t.data(&PersonModel::Patronymic, "Patronymic");

    t.data(&PersonModel::Telephone, "Telephone");
    t.data(&PersonModel::CityTelephone, "CityTelephone");
    t.data(&PersonModel::InternalTelephone, "InternalTelephone");

    t.data(&PersonModel::Email, "Email");
    t.data(&PersonModel::Telegram, "Telegram");
    t.data(&PersonModel::Description, "Description");
}}
