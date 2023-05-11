
#include "gen/GetVehicleAntennaGainResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaGainResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaGainResult::CmdName = "GetVehicleAntennaGainResult";
    const char* const GetVehicleAntennaGainResult::Documentation = "Result of GetVehicleAntennaGain.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetVehicleAntennaGainResult);


    GetVehicleAntennaGainResult::GetVehicleAntennaGainResult()
      : CommandResult(CmdName)
    {}

    GetVehicleAntennaGainResult::GetVehicleAntennaGainResult(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
      : CommandResult(CmdName)
    {

      setGain(gain);
      setType(type);
      setBand(band);
      setName(name);
    }

    GetVehicleAntennaGainResult::GetVehicleAntennaGainResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
      : CommandResult(CmdName, relatedCommand)
    {

      setGain(gain);
      setType(type);
      setBand(band);
      setName(name);
    }


    GetVehicleAntennaGainResultPtr GetVehicleAntennaGainResult::create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaGainResult>(gain, type, band, name);
    }

    GetVehicleAntennaGainResultPtr GetVehicleAntennaGainResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaGainResult>(relatedCommand, gain, type, band, name);
    }

    GetVehicleAntennaGainResultPtr GetVehicleAntennaGainResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaGainResult>(ptr);
    }

    bool GetVehicleAntennaGainResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaGainResult::documentation() const { return Documentation; }


    std::vector<std::vector<double>> GetVehicleAntennaGainResult::gain() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
    }

    void GetVehicleAntennaGainResult::setGain(const std::vector<std::vector<double>>& gain)
    {
      m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaGainResult::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void GetVehicleAntennaGainResult::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand GetVehicleAntennaGainResult::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehicleAntennaGainResult::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetVehicleAntennaGainResult::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaGainResult::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
