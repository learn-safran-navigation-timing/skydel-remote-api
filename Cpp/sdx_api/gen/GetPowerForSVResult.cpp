
#include "gen/GetPowerForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerForSVResult::CmdName = "GetPowerForSVResult";
    const char* const GetPowerForSVResult::Documentation = "Result of GetPowerForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetPowerForSVResult);


    GetPowerForSVResult::GetPowerForSVResult()
      : CommandResult(CmdName)
    {}

    GetPowerForSVResult::GetPowerForSVResult(const std::string& system, int svId, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setNominalPower(nominalPower);
      setSignalStrengthModel(signalStrengthModel);
      setAntenna(antenna);
      setSignalLevelOffset(signalLevelOffset);
      setManualGain(manualGain);
      setTotal(total);
    }

    GetPowerForSVResult::GetPowerForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setNominalPower(nominalPower);
      setSignalStrengthModel(signalStrengthModel);
      setAntenna(antenna);
      setSignalLevelOffset(signalLevelOffset);
      setManualGain(manualGain);
      setTotal(total);
    }


    GetPowerForSVResultPtr GetPowerForSVResult::create(const std::string& system, int svId, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total)
    {
      return std::make_shared<GetPowerForSVResult>(system, svId, nominalPower, signalStrengthModel, antenna, signalLevelOffset, manualGain, total);
    }

    GetPowerForSVResultPtr GetPowerForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total)
    {
      return std::make_shared<GetPowerForSVResult>(relatedCommand, system, svId, nominalPower, signalStrengthModel, antenna, signalLevelOffset, manualGain, total);
    }

    GetPowerForSVResultPtr GetPowerForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerForSVResult>(ptr);
    }

    bool GetPowerForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["NominalPower"])
          && parse_json<double>::is_valid(m_values["SignalStrengthModel"])
          && parse_json<double>::is_valid(m_values["Antenna"])
          && parse_json<double>::is_valid(m_values["SignalLevelOffset"])
          && parse_json<double>::is_valid(m_values["ManualGain"])
          && parse_json<double>::is_valid(m_values["Total"])
        ;

    }

    std::string GetPowerForSVResult::documentation() const { return Documentation; }


    std::string GetPowerForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPowerForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPowerForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPowerForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPowerForSVResult::nominalPower() const
    {
      return parse_json<double>::parse(m_values["NominalPower"]);
    }

    void GetPowerForSVResult::setNominalPower(double nominalPower)
    {
      m_values.AddMember("NominalPower", parse_json<double>::format(nominalPower, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPowerForSVResult::signalStrengthModel() const
    {
      return parse_json<double>::parse(m_values["SignalStrengthModel"]);
    }

    void GetPowerForSVResult::setSignalStrengthModel(double signalStrengthModel)
    {
      m_values.AddMember("SignalStrengthModel", parse_json<double>::format(signalStrengthModel, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPowerForSVResult::antenna() const
    {
      return parse_json<double>::parse(m_values["Antenna"]);
    }

    void GetPowerForSVResult::setAntenna(double antenna)
    {
      m_values.AddMember("Antenna", parse_json<double>::format(antenna, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPowerForSVResult::signalLevelOffset() const
    {
      return parse_json<double>::parse(m_values["SignalLevelOffset"]);
    }

    void GetPowerForSVResult::setSignalLevelOffset(double signalLevelOffset)
    {
      m_values.AddMember("SignalLevelOffset", parse_json<double>::format(signalLevelOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPowerForSVResult::manualGain() const
    {
      return parse_json<double>::parse(m_values["ManualGain"]);
    }

    void GetPowerForSVResult::setManualGain(double manualGain)
    {
      m_values.AddMember("ManualGain", parse_json<double>::format(manualGain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPowerForSVResult::total() const
    {
      return parse_json<double>::parse(m_values["Total"]);
    }

    void GetPowerForSVResult::setTotal(double total)
    {
      m_values.AddMember("Total", parse_json<double>::format(total, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
