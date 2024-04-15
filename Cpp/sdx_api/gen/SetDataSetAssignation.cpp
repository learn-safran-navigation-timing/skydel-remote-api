
#include "SetDataSetAssignation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDataSetAssignation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDataSetAssignation::CmdName = "SetDataSetAssignation";
    const char* const SetDataSetAssignation::Documentation = "Set data set assignation for the specified constellation.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------\n"
      "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "DataSetType string \"Almanac\", \"Ephemeris\" or \"Orbit\"\n"
      "DataSetName string The name of the assigned data set.";
    const char* const SetDataSetAssignation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetDataSetAssignation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetDataSetAssignation);


    SetDataSetAssignation::SetDataSetAssignation()
      : CommandBase(CmdName, TargetId)
    {}

    SetDataSetAssignation::SetDataSetAssignation(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setDataSetType(dataSetType);
      setDataSetName(dataSetName);
    }

    SetDataSetAssignationPtr SetDataSetAssignation::create(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
    {
      return std::make_shared<SetDataSetAssignation>(system, dataSetType, dataSetName);
    }

    SetDataSetAssignationPtr SetDataSetAssignation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetDataSetAssignation>(ptr);
    }

    bool SetDataSetAssignation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetType"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetDataSetAssignation::documentation() const { return Documentation; }

    const std::vector<std::string>& SetDataSetAssignation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "DataSetType", "DataSetName"}; 
      return names; 
    }


    int SetDataSetAssignation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetDataSetAssignation::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetDataSetAssignation::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetDataSetAssignation::dataSetType() const
    {
      return parse_json<std::string>::parse(m_values["DataSetType"]);
    }

    void SetDataSetAssignation::setDataSetType(const std::string& dataSetType)
    {
      m_values.AddMember("DataSetType", parse_json<std::string>::format(dataSetType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetDataSetAssignation::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void SetDataSetAssignation::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
