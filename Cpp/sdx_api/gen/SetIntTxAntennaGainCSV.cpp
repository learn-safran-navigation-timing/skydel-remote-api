
#include "SetIntTxAntennaGainCSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxAntennaGainCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxAntennaGainCSV::CmdName = "SetIntTxAntennaGainCSV";
    const char* const SetIntTxAntennaGainCSV::Documentation = "Set interference transmitter gain antenna pattern from a CSV file.\n"
      "\n"
      "Name     Type               Description\n"
      "-------- ------------------ ----------------------------------------------------------------------------------------------------------------------\n"
      "FilePath string             File path of the CSV (see user manual for CSV file format details). For Default and None types, leave this field empty\n"
      "Type     AntennaPatternType Pattern type\n"
      "Id       string             Transmitter unique identifier.";
    const char* const SetIntTxAntennaGainCSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxAntennaGainCSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxAntennaGainCSV);


    SetIntTxAntennaGainCSV::SetIntTxAntennaGainCSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxAntennaGainCSV::SetIntTxAntennaGainCSV(const std::string& filePath, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setFilePath(filePath);
      setType(type);
      setId(id);
    }

    SetIntTxAntennaGainCSVPtr SetIntTxAntennaGainCSV::create(const std::string& filePath, const Sdx::AntennaPatternType& type, const std::string& id)
    {
      return std::make_shared<SetIntTxAntennaGainCSV>(filePath, type, id);
    }

    SetIntTxAntennaGainCSVPtr SetIntTxAntennaGainCSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxAntennaGainCSV>(ptr);
    }

    bool SetIntTxAntennaGainCSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxAntennaGainCSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxAntennaGainCSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"FilePath", "Type", "Id"}; 
      return names; 
    }


    int SetIntTxAntennaGainCSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetIntTxAntennaGainCSV::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void SetIntTxAntennaGainCSV::setFilePath(const std::string& filePath)
    {
      setValue("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()));
    }



    Sdx::AntennaPatternType SetIntTxAntennaGainCSV::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetIntTxAntennaGainCSV::setType(const Sdx::AntennaPatternType& type)
    {
      setValue("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()));
    }



    std::string SetIntTxAntennaGainCSV::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxAntennaGainCSV::setId(const std::string& id)
    {
      setValue("Id", parse_json<std::string>::format(id, m_values.GetAllocator()));
    }


  }
}
