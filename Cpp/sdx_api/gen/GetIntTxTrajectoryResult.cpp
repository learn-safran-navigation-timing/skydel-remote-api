
#include "GetIntTxTrajectoryResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxTrajectoryResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxTrajectoryResult::CmdName = "GetIntTxTrajectoryResult";
    const char* const GetIntTxTrajectoryResult::Documentation = "Result of GetIntTxTrajectory.\n"
      "\n"
      "Name           Type   Description\n"
      "-------------- ------ ---------------------------------------------------------\n"
      "TrajectoryType string Type of the trajectory of the interferences transmitters.\n"
      "Id             string Transmitter unique identifier.";
    const char* const GetIntTxTrajectoryResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxTrajectoryResult);


    GetIntTxTrajectoryResult::GetIntTxTrajectoryResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxTrajectoryResult::GetIntTxTrajectoryResult(const std::string& trajectoryType, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setTrajectoryType(trajectoryType);
      setId(id);
    }

    GetIntTxTrajectoryResult::GetIntTxTrajectoryResult(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setTrajectoryType(trajectoryType);
      setId(id);
    }


    GetIntTxTrajectoryResultPtr GetIntTxTrajectoryResult::create(const std::string& trajectoryType, const std::string& id)
    {
      return std::make_shared<GetIntTxTrajectoryResult>(trajectoryType, id);
    }

    GetIntTxTrajectoryResultPtr GetIntTxTrajectoryResult::create(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id)
    {
      return std::make_shared<GetIntTxTrajectoryResult>(relatedCommand, trajectoryType, id);
    }

    GetIntTxTrajectoryResultPtr GetIntTxTrajectoryResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxTrajectoryResult>(ptr);
    }

    bool GetIntTxTrajectoryResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TrajectoryType"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxTrajectoryResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxTrajectoryResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TrajectoryType", "Id"}; 
      return names; 
    }


    std::string GetIntTxTrajectoryResult::trajectoryType() const
    {
      return parse_json<std::string>::parse(m_values["TrajectoryType"]);
    }

    void GetIntTxTrajectoryResult::setTrajectoryType(const std::string& trajectoryType)
    {
      m_values.AddMember("TrajectoryType", parse_json<std::string>::format(trajectoryType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxTrajectoryResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxTrajectoryResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
