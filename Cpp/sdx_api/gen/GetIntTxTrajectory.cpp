
#include "GetIntTxTrajectory.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxTrajectory
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxTrajectory::CmdName = "GetIntTxTrajectory";
    const char* const GetIntTxTrajectory::Documentation = "Get interference transmitter trajectory.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTxTrajectory::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxTrajectory);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxTrajectory);


    GetIntTxTrajectory::GetIntTxTrajectory()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxTrajectory::GetIntTxTrajectory(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxTrajectoryPtr GetIntTxTrajectory::create(const std::string& id)
    {
      return std::make_shared<GetIntTxTrajectory>(id);
    }

    GetIntTxTrajectoryPtr GetIntTxTrajectory::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxTrajectory>(ptr);
    }

    bool GetIntTxTrajectory::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxTrajectory::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxTrajectory::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTxTrajectory::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxTrajectory::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxTrajectory::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
