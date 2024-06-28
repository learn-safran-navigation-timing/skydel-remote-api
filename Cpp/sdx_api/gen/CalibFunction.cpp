
#include "CalibFunction.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of CalibFunction
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const CalibFunction::CmdName = "CalibFunction";
    const char* const CalibFunction::Documentation = "Skydel special calibration function, internal use only\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "SvId          int    SV ID for GPS, Galileo, BeiDou, GLONASS, QZSS, NavIC and SBAS.\n"
      "Signal        string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\"\n"
      "EnableSV      bool   Enable/Disable multiplication by satellite and Navigation Message\n"
      "EnableDoppler bool   Enable/Disable Doppler Frequency and Phase offset\n"
      "PhaseOffet    double Carrier Phase Offset applied to Line Of Sight";
    const char* const CalibFunction::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(CalibFunction);
    REGISTER_COMMAND_TO_FACTORY_IMPL(CalibFunction);


    CalibFunction::CalibFunction()
      : CommandBase(CmdName, TargetId)
    {}

    CalibFunction::CalibFunction(int svId, const std::string& signal, bool enableSV, bool enableDoppler, double phaseOffet)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setSignal(signal);
      setEnableSV(enableSV);
      setEnableDoppler(enableDoppler);
      setPhaseOffet(phaseOffet);
    }

    CalibFunctionPtr CalibFunction::create(int svId, const std::string& signal, bool enableSV, bool enableDoppler, double phaseOffet)
    {
      return std::make_shared<CalibFunction>(svId, signal, enableSV, enableDoppler, phaseOffet);
    }

    CalibFunctionPtr CalibFunction::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<CalibFunction>(ptr);
    }

    bool CalibFunction::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["EnableSV"])
          && parse_json<bool>::is_valid(m_values["EnableDoppler"])
          && parse_json<double>::is_valid(m_values["PhaseOffet"])
        ;

    }

    std::string CalibFunction::documentation() const { return Documentation; }

    const std::vector<std::string>& CalibFunction::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Signal", "EnableSV", "EnableDoppler", "PhaseOffet"}; 
      return names; 
    }


    int CalibFunction::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    int CalibFunction::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void CalibFunction::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string CalibFunction::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void CalibFunction::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool CalibFunction::enableSV() const
    {
      return parse_json<bool>::parse(m_values["EnableSV"]);
    }

    void CalibFunction::setEnableSV(bool enableSV)
    {
      m_values.AddMember("EnableSV", parse_json<bool>::format(enableSV, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool CalibFunction::enableDoppler() const
    {
      return parse_json<bool>::parse(m_values["EnableDoppler"]);
    }

    void CalibFunction::setEnableDoppler(bool enableDoppler)
    {
      m_values.AddMember("EnableDoppler", parse_json<bool>::format(enableDoppler, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double CalibFunction::phaseOffet() const
    {
      return parse_json<double>::parse(m_values["PhaseOffet"]);
    }

    void CalibFunction::setPhaseOffet(double phaseOffet)
    {
      m_values.AddMember("PhaseOffet", parse_json<double>::format(phaseOffet, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
