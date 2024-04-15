
#include "SetSVAntennaGainCSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVAntennaGainCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVAntennaGainCSV::CmdName = "SetSVAntennaGainCSV";
    const char* const SetSVAntennaGainCSV::Documentation = "Set space vehicle gain antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic SV Antenna.\n"
      "\n"
      "Name     Type               Description\n"
      "-------- ------------------ ------------------------------------------------------------------------------------------------------------------\n"
      "FilePath string             File path of the CSV. For Default and None type, lets it empty. See formats in user manual part 8.7.9.2.1. Models.\n"
      "Type     AntennaPatternType Pattern type\n"
      "Band     GNSSBand           Frequency band\n"
      "System   string             \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Name     optional string    Vehicle antenna name";
    const char* const SetSVAntennaGainCSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSVAntennaGainCSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSVAntennaGainCSV);


    SetSVAntennaGainCSV::SetSVAntennaGainCSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetSVAntennaGainCSV::SetSVAntennaGainCSV(const std::string& filePath, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName, TargetId)
    {

      setFilePath(filePath);
      setType(type);
      setBand(band);
      setSystem(system);
      setName(name);
    }

    SetSVAntennaGainCSVPtr SetSVAntennaGainCSV::create(const std::string& filePath, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<SetSVAntennaGainCSV>(filePath, type, band, system, name);
    }

    SetSVAntennaGainCSVPtr SetSVAntennaGainCSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVAntennaGainCSV>(ptr);
    }

    bool SetSVAntennaGainCSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string SetSVAntennaGainCSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSVAntennaGainCSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"FilePath", "Type", "Band", "System", "Name"}; 
      return names; 
    }


    int SetSVAntennaGainCSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSVAntennaGainCSV::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void SetSVAntennaGainCSV::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetSVAntennaGainCSV::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetSVAntennaGainCSV::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand SetSVAntennaGainCSV::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void SetSVAntennaGainCSV::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSVAntennaGainCSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSVAntennaGainCSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetSVAntennaGainCSV::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void SetSVAntennaGainCSV::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
