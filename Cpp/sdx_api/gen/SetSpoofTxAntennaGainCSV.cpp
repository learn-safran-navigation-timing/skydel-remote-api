
#include "SetSpoofTxAntennaGainCSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxAntennaGainCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxAntennaGainCSV::CmdName = "SetSpoofTxAntennaGainCSV";
    const char* const SetSpoofTxAntennaGainCSV::Documentation = "Set spoofer transmitter gain antenna pattern from a CSV file.\n"
      "\n"
      "Name     Type               Description\n"
      "-------- ------------------ ----------------------------------------------------------------------------------------------------------------------\n"
      "FilePath string             File path of the CSV (see user manual for CSV file format details). For Default and None types, leave this field empty\n"
      "Type     AntennaPatternType Pattern type\n"
      "Id       string             Transmitter unique identifier.";
    const char* const SetSpoofTxAntennaGainCSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxAntennaGainCSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxAntennaGainCSV);


    SetSpoofTxAntennaGainCSV::SetSpoofTxAntennaGainCSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxAntennaGainCSV::SetSpoofTxAntennaGainCSV(const std::string& filePath, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setFilePath(filePath);
      setType(type);
      setId(id);
    }

    SetSpoofTxAntennaGainCSVPtr SetSpoofTxAntennaGainCSV::create(const std::string& filePath, const Sdx::AntennaPatternType& type, const std::string& id)
    {
      return std::make_shared<SetSpoofTxAntennaGainCSV>(filePath, type, id);
    }

    SetSpoofTxAntennaGainCSVPtr SetSpoofTxAntennaGainCSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxAntennaGainCSV>(ptr);
    }

    bool SetSpoofTxAntennaGainCSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxAntennaGainCSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxAntennaGainCSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"FilePath", "Type", "Id"}; 
      return names; 
    }


    int SetSpoofTxAntennaGainCSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSpoofTxAntennaGainCSV::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void SetSpoofTxAntennaGainCSV::setFilePath(const std::string& filePath)
    {
      setValue("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()));
    }



    Sdx::AntennaPatternType SetSpoofTxAntennaGainCSV::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetSpoofTxAntennaGainCSV::setType(const Sdx::AntennaPatternType& type)
    {
      setValue("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()));
    }



    std::string SetSpoofTxAntennaGainCSV::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxAntennaGainCSV::setId(const std::string& id)
    {
      setValue("Id", parse_json<std::string>::format(id, m_values.GetAllocator()));
    }


  }
}
