
#include "GetSpoofTxTrajectoryResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxTrajectoryResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxTrajectoryResult::CmdName = "GetSpoofTxTrajectoryResult";
    const char* const GetSpoofTxTrajectoryResult::Documentation = "Result of GetSpoofTxTrajectory.\n"
      "\n"
      "Name           Type   Description\n"
      "-------------- ------ ---------------------------------------------------\n"
      "TrajectoryType string Type of the trajectory of the spoofer transmitters.\n"
      "Id             string Transmitter unique identifier.";
    const char* const GetSpoofTxTrajectoryResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxTrajectoryResult);


    GetSpoofTxTrajectoryResult::GetSpoofTxTrajectoryResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSpoofTxTrajectoryResult::GetSpoofTxTrajectoryResult(const std::string& trajectoryType, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setTrajectoryType(trajectoryType);
      setId(id);
    }

    GetSpoofTxTrajectoryResult::GetSpoofTxTrajectoryResult(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setTrajectoryType(trajectoryType);
      setId(id);
    }


    GetSpoofTxTrajectoryResultPtr GetSpoofTxTrajectoryResult::create(const std::string& trajectoryType, const std::string& id)
    {
      return std::make_shared<GetSpoofTxTrajectoryResult>(trajectoryType, id);
    }

    GetSpoofTxTrajectoryResultPtr GetSpoofTxTrajectoryResult::create(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id)
    {
      return std::make_shared<GetSpoofTxTrajectoryResult>(relatedCommand, trajectoryType, id);
    }

    GetSpoofTxTrajectoryResultPtr GetSpoofTxTrajectoryResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxTrajectoryResult>(ptr);
    }

    bool GetSpoofTxTrajectoryResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TrajectoryType"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxTrajectoryResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxTrajectoryResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TrajectoryType", "Id"}; 
      return names; 
    }


    std::string GetSpoofTxTrajectoryResult::trajectoryType() const
    {
      return parse_json<std::string>::parse(m_values["TrajectoryType"]);
    }

    void GetSpoofTxTrajectoryResult::setTrajectoryType(const std::string& trajectoryType)
    {
      m_values.AddMember("TrajectoryType", parse_json<std::string>::format(trajectoryType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxTrajectoryResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxTrajectoryResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
