
#include "gen/GetIntTxVehicleType.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxVehicleType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxVehicleType::CmdName = "GetIntTxVehicleType";
    const char* const GetIntTxVehicleType::Documentation = "Get Set interference vehicle type for Track Trajectory";

    REGISTER_COMMAND_FACTORY(GetIntTxVehicleType);


    GetIntTxVehicleType::GetIntTxVehicleType()
      : CommandBase(CmdName)
    {}

    GetIntTxVehicleType::GetIntTxVehicleType(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetIntTxVehicleTypePtr GetIntTxVehicleType::create(const std::string& id)
    {
      return std::make_shared<GetIntTxVehicleType>(id);
    }

    GetIntTxVehicleTypePtr GetIntTxVehicleType::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxVehicleType>(ptr);
    }

    bool GetIntTxVehicleType::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxVehicleType::documentation() const { return Documentation; }


    int GetIntTxVehicleType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxVehicleType::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxVehicleType::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
