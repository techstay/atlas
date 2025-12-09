from datetime import date

from pydantic import BaseModel, ConfigDict, Field


class User(BaseModel):
    id: int
    name: str
    birthday: date
    nick_name: str | None = Field(
        alias="nickName",
        default=None,
    )

    model_config = ConfigDict(
        serialize_by_alias=True,
    )


user = User(id=1, name="techstay", birthday=date(1998, 8, 24), nickName="TechBoy")

json = user.model_dump_json(indent=2)

print(json)

user = User.model_validate_json(
    '{"id": 2, "name": "jack", "birthday": "1998-08-22", "nickName": "jackBoy"}'
)
print(user)
