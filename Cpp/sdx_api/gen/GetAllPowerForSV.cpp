
#include "GetAllPowerForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllPowerForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllPowerForSV::CmdName = "GetAllPowerForSV";
    const char* const GetAllPowerForSV::Documentation = "Get the power information for the specified satellite.\n"
      "\n"
      "Name        Type         Description\n"
      "----------- ------------ -------------------------------------------------------------------------------\n"
      "System      string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "SvId        int          The Satellite's SV ID.\n"
      "SignalArray array string An array of signals.\n"
      "                         Accepted values are: \"All\", \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\",\n"
      "                                              \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\",\n"
      "                                              \"E5b\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\",\n"
      "                                              \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
      "                                              \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"NAVICL5\" and\n"
      "                                              \"PULSARXL\"";
    const char* const GetAllPowerForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllPowerForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllPowerForSV);


    GetAllPowerForSV::GetAllPowerForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllPowerForSV::GetAllPowerForSV(const std::string& system, int svId, const std::vector<std::string>& signalArray)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setSignalArray(signalArray);
    }

    GetAllPowerForSVPtr GetAllPowerForSV::create(const std::string& system, int svId, const std::vector<std::string>& signalArray)
    {
      return std::make_shared<GetAllPowerForSV>(system, svId, signalArray);
    }

    GetAllPowerForSVPtr GetAllPowerForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllPowerForSV>(ptr);
    }

    bool GetAllPowerForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
        ;

    }

    std::string GetAllPowerForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllPowerForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "SignalArray"}; 
      return names; 
    }


    int GetAllPowerForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetAllPowerForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllPowerForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllPowerForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetAllPowerForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetAllPowerForSV::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetAllPowerForSV::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
