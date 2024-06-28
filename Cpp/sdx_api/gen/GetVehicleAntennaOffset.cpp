
#include "GetVehicleAntennaOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaOffset::CmdName = "GetVehicleAntennaOffset";
    const char* const GetVehicleAntennaOffset::Documentation = "Get the vehicle antenna offset infos. If no name is specified, the default vehicle antenna is get.\n"
      "\n"
      "Name Type            Description\n"
      "---- --------------- ---------------------------\n"
      "Name optional string Unique vehicle antenna name";
    const char* const GetVehicleAntennaOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleAntennaOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleAntennaOffset);


    GetVehicleAntennaOffset::GetVehicleAntennaOffset(const std::optional<std::string>& name)
      : CommandBase(CmdName, TargetId)
    {

      setName(name);
    }

    GetVehicleAntennaOffsetPtr GetVehicleAntennaOffset::create(const std::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaOffset>(name);
    }

    GetVehicleAntennaOffsetPtr GetVehicleAntennaOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaOffset>(ptr);
    }

    bool GetVehicleAntennaOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleAntennaOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Name"}; 
      return names; 
    }


    int GetVehicleAntennaOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::optional<std::string> GetVehicleAntennaOffset::name() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaOffset::setName(const std::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
