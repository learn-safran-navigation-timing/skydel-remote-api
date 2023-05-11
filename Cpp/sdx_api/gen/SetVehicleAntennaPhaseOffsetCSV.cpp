
#include "gen/SetVehicleAntennaPhaseOffsetCSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleAntennaPhaseOffsetCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleAntennaPhaseOffsetCSV::CmdName = "SetVehicleAntennaPhaseOffsetCSV";
    const char* const SetVehicleAntennaPhaseOffsetCSV::Documentation = "Set vehicle phase offset antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic vehicle Antenna.";

    REGISTER_COMMAND_FACTORY(SetVehicleAntennaPhaseOffsetCSV);


    SetVehicleAntennaPhaseOffsetCSV::SetVehicleAntennaPhaseOffsetCSV()
      : CommandBase(CmdName)
    {}

    SetVehicleAntennaPhaseOffsetCSV::SetVehicleAntennaPhaseOffsetCSV(const std::string& filePath, const Sdx::AntennaPatternFileType& fileFormat, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName)
    {

      setFilePath(filePath);
      setFileFormat(fileFormat);
      setType(type);
      setBand(band);
      setName(name);
    }

    SetVehicleAntennaPhaseOffsetCSVPtr SetVehicleAntennaPhaseOffsetCSV::create(const std::string& filePath, const Sdx::AntennaPatternFileType& fileFormat, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<SetVehicleAntennaPhaseOffsetCSV>(filePath, fileFormat, type, band, name);
    }

    SetVehicleAntennaPhaseOffsetCSVPtr SetVehicleAntennaPhaseOffsetCSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleAntennaPhaseOffsetCSV>(ptr);
    }

    bool SetVehicleAntennaPhaseOffsetCSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<Sdx::AntennaPatternFileType>::is_valid(m_values["FileFormat"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string SetVehicleAntennaPhaseOffsetCSV::documentation() const { return Documentation; }


    int SetVehicleAntennaPhaseOffsetCSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetVehicleAntennaPhaseOffsetCSV::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void SetVehicleAntennaPhaseOffsetCSV::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternFileType SetVehicleAntennaPhaseOffsetCSV::fileFormat() const
    {
      return parse_json<Sdx::AntennaPatternFileType>::parse(m_values["FileFormat"]);
    }

    void SetVehicleAntennaPhaseOffsetCSV::setFileFormat(const Sdx::AntennaPatternFileType& fileFormat)
    {
      m_values.AddMember("FileFormat", parse_json<Sdx::AntennaPatternFileType>::format(fileFormat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetVehicleAntennaPhaseOffsetCSV::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetVehicleAntennaPhaseOffsetCSV::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand SetVehicleAntennaPhaseOffsetCSV::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void SetVehicleAntennaPhaseOffsetCSV::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetVehicleAntennaPhaseOffsetCSV::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void SetVehicleAntennaPhaseOffsetCSV::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
