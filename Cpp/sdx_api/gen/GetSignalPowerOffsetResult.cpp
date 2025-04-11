
#include "GetSignalPowerOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalPowerOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalPowerOffsetResult::CmdName = "GetSignalPowerOffsetResult";
    const char* const GetSignalPowerOffsetResult::Documentation = "Result of GetSignalPowerOffset.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                    \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                    \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\",\n"
      "                                    \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
      "                                    \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"
      "Offset double Offset in dB (negative value will attenuate signal)";
    const char* const GetSignalPowerOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSignalPowerOffsetResult);


    GetSignalPowerOffsetResult::GetSignalPowerOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSignalPowerOffsetResult::GetSignalPowerOffsetResult(const std::string& signal, double offset)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setOffset(offset);
    }

    GetSignalPowerOffsetResult::GetSignalPowerOffsetResult(CommandBasePtr relatedCommand, const std::string& signal, double offset)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetSignalPowerOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Offset"}; 
      return names; 
    }


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
