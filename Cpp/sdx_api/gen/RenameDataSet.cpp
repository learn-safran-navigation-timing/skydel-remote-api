
#include "RenameDataSet.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RenameDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RenameDataSet::CmdName = "RenameDataSet";
    const char* const RenameDataSet::Documentation = "Rename data set.\n"
      "\n"
      "Name           Type   Description\n"
      "-------------- ------ -------------------------------------------------------\n"
      "System         string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "DataSetName    string The name of the data set to rename.\n"
      "NewDataSetName string The new name to be given to the data set.";
    const char* const RenameDataSet::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RenameDataSet);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RenameDataSet);


    RenameDataSet::RenameDataSet()
      : CommandBase(CmdName, TargetId)
    {}

    RenameDataSet::RenameDataSet(const std::string& system, const std::string& dataSetName, const std::string& newDataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setDataSetName(dataSetName);
      setNewDataSetName(newDataSetName);
    }

    RenameDataSetPtr RenameDataSet::create(const std::string& system, const std::string& dataSetName, const std::string& newDataSetName)
    {
      return std::make_shared<RenameDataSet>(system, dataSetName, newDataSetName);
    }

    RenameDataSetPtr RenameDataSet::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RenameDataSet>(ptr);
    }

    bool RenameDataSet::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
          && parse_json<std::string>::is_valid(m_values["NewDataSetName"])
        ;

    }

    std::string RenameDataSet::documentation() const { return Documentation; }

    const std::vector<std::string>& RenameDataSet::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "DataSetName", "NewDataSetName"}; 
      return names; 
    }


    int RenameDataSet::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RenameDataSet::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RenameDataSet::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RenameDataSet::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void RenameDataSet::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RenameDataSet::newDataSetName() const
    {
      return parse_json<std::string>::parse(m_values["NewDataSetName"]);
    }

    void RenameDataSet::setNewDataSetName(const std::string& newDataSetName)
    {
      m_values.AddMember("NewDataSetName", parse_json<std::string>::format(newDataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
