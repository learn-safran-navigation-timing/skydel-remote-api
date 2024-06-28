
#include "DuplicateDataSet.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of DuplicateDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const DuplicateDataSet::CmdName = "DuplicateDataSet";
    const char* const DuplicateDataSet::Documentation = "Duplicate an existing data set.\n"
      "\n"
      "Name           Type            Description\n"
      "-------------- --------------- ----------------------------------------------------------------------------------\n"
      "System         string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "DataSetName    string          The name of the data set to duplicate.\n"
      "NewDataSetName optional string The name of the new duplicate data set. If omitted, a copy name will be generated.";
    const char* const DuplicateDataSet::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(DuplicateDataSet);
    REGISTER_COMMAND_TO_FACTORY_IMPL(DuplicateDataSet);


    DuplicateDataSet::DuplicateDataSet()
      : CommandBase(CmdName, TargetId)
    {}

    DuplicateDataSet::DuplicateDataSet(const std::string& system, const std::string& dataSetName, const std::optional<std::string>& newDataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setDataSetName(dataSetName);
      setNewDataSetName(newDataSetName);
    }

    DuplicateDataSetPtr DuplicateDataSet::create(const std::string& system, const std::string& dataSetName, const std::optional<std::string>& newDataSetName)
    {
      return std::make_shared<DuplicateDataSet>(system, dataSetName, newDataSetName);
    }

    DuplicateDataSetPtr DuplicateDataSet::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<DuplicateDataSet>(ptr);
    }

    bool DuplicateDataSet::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["NewDataSetName"])
        ;

    }

    std::string DuplicateDataSet::documentation() const { return Documentation; }

    const std::vector<std::string>& DuplicateDataSet::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "DataSetName", "NewDataSetName"}; 
      return names; 
    }


    int DuplicateDataSet::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string DuplicateDataSet::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void DuplicateDataSet::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string DuplicateDataSet::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void DuplicateDataSet::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> DuplicateDataSet::newDataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["NewDataSetName"]);
    }

    void DuplicateDataSet::setNewDataSetName(const std::optional<std::string>& newDataSetName)
    {
      m_values.AddMember("NewDataSetName", parse_json<std::optional<std::string>>::format(newDataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
