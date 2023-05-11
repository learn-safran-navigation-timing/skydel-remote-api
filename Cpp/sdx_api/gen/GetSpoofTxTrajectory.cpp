
#include "gen/GetSpoofTxTrajectory.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxTrajectory
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxTrajectory::CmdName = "GetSpoofTxTrajectory";
    const char* const GetSpoofTxTrajectory::Documentation = "Get spoofer transmitter trajectory";

    REGISTER_COMMAND_FACTORY(GetSpoofTxTrajectory);


    GetSpoofTxTrajectory::GetSpoofTxTrajectory()
      : CommandBase(CmdName)
    {}

    GetSpoofTxTrajectory::GetSpoofTxTrajectory(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetSpoofTxTrajectoryPtr GetSpoofTxTrajectory::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTxTrajectory>(id);
    }

    GetSpoofTxTrajectoryPtr GetSpoofTxTrajectory::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxTrajectory>(ptr);
    }

    bool GetSpoofTxTrajectory::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxTrajectory::documentation() const { return Documentation; }


    int GetSpoofTxTrajectory::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTxTrajectory::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxTrajectory::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
