
#include "GetManualPowerOffsetForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetManualPowerOffsetForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetManualPowerOffsetForSV::CmdName = "GetManualPowerOffsetForSV";
    const char* const GetManualPowerOffsetForSV::Documentation = "Get the power offsets for specific signals of a satellite.\n"
      "\n"
      "Name        Type         Description\n"
      "----------- ------------ -------------------------------------------------------------------------------\n"
      "System      string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "SvId        int          The satellite's SV ID.\n"
      "SignalArray array string An array of signals.\n"
      "                         Accepted values are: \"All\", \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\",\n"
      "                                              \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\",\n"
      "                                              \"E5b\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\",\n"
      "                                              \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
      "                                              \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"NAVICL5\" and\n"
      "                                              \"PULSARXL\"";
    const char* const GetManualPowerOffsetForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetManualPowerOffsetForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetManualPowerOffsetForSV);


    GetManualPowerOffsetForSV::GetManualPowerOffsetForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetManualPowerOffsetForSV::GetManualPowerOffsetForSV(const std::string& system, int svId, const std::vector<std::string>& signalArray)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setSignalArray(signalArray);
    }

    GetManualPowerOffsetForSVPtr GetManualPowerOffsetForSV::create(const std::string& system, int svId, const std::vector<std::string>& signalArray)
    {
      return std::make_shared<GetManualPowerOffsetForSV>(system, svId, signalArray);
    }

    GetManualPowerOffsetForSVPtr GetManualPowerOffsetForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetManualPowerOffsetForSV>(ptr);
    }

    bool GetManualPowerOffsetForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
        ;

    }

    std::string GetManualPowerOffsetForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetManualPowerOffsetForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "SignalArray"}; 
      return names; 
    }


    int GetManualPowerOffsetForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetManualPowerOffsetForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetManualPowerOffsetForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetManualPowerOffsetForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetManualPowerOffsetForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetManualPowerOffsetForSV::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetManualPowerOffsetForSV::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
