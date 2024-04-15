
#include "GetIntTxAntennaOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxAntennaOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxAntennaOffset::CmdName = "GetIntTxAntennaOffset";
    const char* const GetIntTxAntennaOffset::Documentation = "Get antenna offset and orientation relative to body frame.\n"
      "The origin of the body frame follows the transmitter trajectory.\n"
      "When the body yaw/pitch/roll are zeros, the body X-axis is pointing north\n"
      "                         Y-axis is pointing east\n"
      "                         Z-axis is pointing down\n"
      "The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and\n"
      "the Roll is rotating arond the X-axis of the body frame.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTxAntennaOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxAntennaOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxAntennaOffset);


    GetIntTxAntennaOffset::GetIntTxAntennaOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxAntennaOffset::GetIntTxAntennaOffset(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxAntennaOffsetPtr GetIntTxAntennaOffset::create(const std::string& id)
    {
      return std::make_shared<GetIntTxAntennaOffset>(id);
    }

    GetIntTxAntennaOffsetPtr GetIntTxAntennaOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxAntennaOffset>(ptr);
    }

    bool GetIntTxAntennaOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxAntennaOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxAntennaOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTxAntennaOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxAntennaOffset::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxAntennaOffset::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
