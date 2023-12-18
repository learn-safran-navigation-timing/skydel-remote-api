
#include "gen/GetEphemerisTocOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisTocOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisTocOffsetResult::CmdName = "GetEphemerisTocOffsetResult";
    const char* const GetEphemerisTocOffsetResult::Documentation = "Result of GetEphemerisTocOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetEphemerisTocOffsetResult);


    GetEphemerisTocOffsetResult::GetEphemerisTocOffsetResult()
      : CommandResult(CmdName)
    {}

    GetEphemerisTocOffsetResult::GetEphemerisTocOffsetResult(const std::string& system, int offset)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setOffset(offset);
    }

    GetEphemerisTocOffsetResult::GetEphemerisTocOffsetResult(CommandBasePtr relatedCommand, const std::string& system, int offset)
      : CommandResult(CmdName, relatedCommand)
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
