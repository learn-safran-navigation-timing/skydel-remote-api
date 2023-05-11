
#include "gen/GetSignalPowerOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalPowerOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalPowerOffsetResult::CmdName = "GetSignalPowerOffsetResult";
    const char* const GetSignalPowerOffsetResult::Documentation = "Result of GetSignalPowerOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSignalPowerOffsetResult);


    GetSignalPowerOffsetResult::GetSignalPowerOffsetResult()
      : CommandResult(CmdName)
    {}

    GetSignalPowerOffsetResult::GetSignalPowerOffsetResult(const std::string& signal, double offset)
      : CommandResult(CmdName)
    {

      setSignal(signal);
      setOffset(offset);
    }

    GetSignalPowerOffsetResult::GetSignalPowerOffsetResult(CommandBasePtr relatedCommand, const std::string& signal, double offset)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setOffset(offset);
    }


    GetSignalPowerOffsetResultPtr GetSignalPowerOffsetResult::create(const std::string& signal, double offset)
    {
      return std::make_shared<GetSignalPowerOffsetResult>(signal, offset);
    }

    GetSignalPowerOffsetResultPtr GetSignalPowerOffsetResult::create(CommandBasePtr relatedCommand, const std::string& signal, double offset)
    {
      return std::make_shared<GetSignalPowerOffsetResult>(relatedCommand, signal, offset);
    }

    GetSignalPowerOffsetResultPtr GetSignalPowerOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSignalPowerOffsetResult>(ptr);
    }

    bool GetSignalPowerOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetSignalPowerOffsetResult::documentation() const { return Documentation; }


    std::string GetSignalPowerOffsetResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetSignalPowerOffsetResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSignalPowerOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetSignalPowerOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
