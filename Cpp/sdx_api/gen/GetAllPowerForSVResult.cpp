
#include "gen/GetAllPowerForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllPowerForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllPowerForSVResult::CmdName = "GetAllPowerForSVResult";
    const char* const GetAllPowerForSVResult::Documentation = "Result of GetAllPowerForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetAllPowerForSVResult);


    GetAllPowerForSVResult::GetAllPowerForSVResult()
      : CommandResult(CmdName)
    {}

    GetAllPowerForSVResult::GetAllPowerForSVResult(const std::string& system, int svId, double nominalPower, double globalOffset, const std::map<std::string, Sdx::SignalPower>& signalPowerDict)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setNominalPower(nominalPower);
      setGlobalOffset(globalOffset);
      setSignalPowerDict(signalPowerDict);
    }

    GetAllPowerForSVResult::GetAllPowerForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double nominalPower, double globalOffset, const std::map<std::string, Sdx::SignalPower>& signalPowerDict)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setNominalPower(nominalPower);
      setGlobalOffset(globalOffset);
      setSignalPowerDict(signalPowerDict);
    }


    GetAllPowerForSVResultPtr GetAllPowerForSVResult::create(const std::string& system, int svId, double nominalPower, double globalOffset, const std::map<std::string, Sdx::SignalPower>& signalPowerDict)
    {
      return std::make_shared<GetAllPowerForSVResult>(system, svId, nominalPower, globalOffset, signalPowerDict);
    }

    GetAllPowerForSVResultPtr GetAllPowerForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, double nominalPower, double globalOffset, const std::map<std::string, Sdx::SignalPower>& signalPowerDict)
    {
      return std::make_shared<GetAllPowerForSVResult>(relatedCommand, system, svId, nominalPower, globalOffset, signalPowerDict);
    }

    GetAllPowerForSVResultPtr GetAllPowerForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllPowerForSVResult>(ptr);
    }

    bool GetAllPowerForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["NominalPower"])
          && parse_json<double>::is_valid(m_values["GlobalOffset"])
          && parse_json<std::map<std::string, Sdx::SignalPower>>::is_valid(m_values["SignalPowerDict"])
        ;

    }

    std::string GetAllPowerForSVResult::documentation() const { return Documentation; }


    std::string GetAllPowerForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllPowerForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllPowerForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetAllPowerForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetAllPowerForSVResult::nominalPower() const
    {
      return parse_json<double>::parse(m_values["NominalPower"]);
    }

    void GetAllPowerForSVResult::setNominalPower(double nominalPower)
    {
      m_values.AddMember("NominalPower", parse_json<double>::format(nominalPower, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetAllPowerForSVResult::globalOffset() const
    {
      return parse_json<double>::parse(m_values["GlobalOffset"]);
    }

    void GetAllPowerForSVResult::setGlobalOffset(double globalOffset)
    {
      m_values.AddMember("GlobalOffset", parse_json<double>::format(globalOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, Sdx::SignalPower> GetAllPowerForSVResult::signalPowerDict() const
    {
      return parse_json<std::map<std::string, Sdx::SignalPower>>::parse(m_values["SignalPowerDict"]);
    }

    void GetAllPowerForSVResult::setSignalPowerDict(const std::map<std::string, Sdx::SignalPower>& signalPowerDict)
    {
      m_values.AddMember("SignalPowerDict", parse_json<std::map<std::string, Sdx::SignalPower>>::format(signalPowerDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
