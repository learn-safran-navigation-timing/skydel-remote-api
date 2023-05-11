
#include "gen/SetVehicleAntennaGainCSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleAntennaGainCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleAntennaGainCSV::CmdName = "SetVehicleAntennaGainCSV";
    const char* const SetVehicleAntennaGainCSV::Documentation = "Set vehicle gain antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic vehicle Antenna.";

    REGISTER_COMMAND_FACTORY(SetVehicleAntennaGainCSV);


    SetVehicleAntennaGainCSV::SetVehicleAntennaGainCSV()
      : CommandBase(CmdName)
    {}

    SetVehicleAntennaGainCSV::SetVehicleAntennaGainCSV(const std::string& filePath, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName)
    {

      setFilePath(filePath);
      setType(type);
      setBand(band);
      setName(name);
    }

    SetVehicleAntennaGainCSVPtr SetVehicleAntennaGainCSV::create(const std::string& filePath, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<SetVehicleAntennaGainCSV>(filePath, type, band, name);
    }

    SetVehicleAntennaGainCSVPtr SetVehicleAntennaGainCSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleAntennaGainCSV>(ptr);
    }

    bool SetVehicleAntennaGainCSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string SetVehicleAntennaGainCSV::documentation() const { return Documentation; }


    int SetVehicleAntennaGainCSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetVehicleAntennaGainCSV::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void SetVehicleAntennaGainCSV::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetVehicleAntennaGainCSV::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetVehicleAntennaGainCSV::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand SetVehicleAntennaGainCSV::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void SetVehicleAntennaGainCSV::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetVehicleAntennaGainCSV::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void SetVehicleAntennaGainCSV::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
