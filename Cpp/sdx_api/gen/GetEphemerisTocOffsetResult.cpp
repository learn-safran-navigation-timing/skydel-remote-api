
#include "GetEphemerisTocOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisTocOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisTocOffsetResult::CmdName = "GetEphemerisTocOffsetResult";
    const char* const GetEphemerisTocOffsetResult::Documentation = "Result of GetEphemerisTocOffset.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------\n"
      "System string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Offset int    Offset in sec. Accepted range is [-604800..604800].";
    const char* const GetEphemerisTocOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEphemerisTocOffsetResult);


    GetEphemerisTocOffsetResult::GetEphemerisTocOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetEphemerisTocOffsetResult::GetEphemerisTocOffsetResult(const std::string& system, int offset)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setOffset(offset);
    }

    GetEphemerisTocOffsetResult::GetEphemerisTocOffsetResult(CommandBasePtr relatedCommand, const std::string& system, int offset)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setOffset(offset);
    }


    GetEphemerisTocOffsetResultPtr GetEphemerisTocOffsetResult::create(const std::string& system, int offset)
    {
      return std::make_shared<GetEphemerisTocOffsetResult>(system, offset);
    }

    GetEphemerisTocOffsetResultPtr GetEphemerisTocOffsetResult::create(CommandBasePtr relatedCommand, const std::string& system, int offset)
    {
      return std::make_shared<GetEphemerisTocOffsetResult>(relatedCommand, system, offset);
    }

    GetEphemerisTocOffsetResultPtr GetEphemerisTocOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisTocOffsetResult>(ptr);
    }

    bool GetEphemerisTocOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetEphemerisTocOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEphemerisTocOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Offset"}; 
      return names; 
    }


    std::string GetEphemerisTocOffsetResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisTocOffsetResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisTocOffsetResult::offset() const
    {
      return parse_json<int>::parse(m_values["Offset"]);
    }

    void GetEphemerisTocOffsetResult::setOffset(int offset)
    {
      m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
