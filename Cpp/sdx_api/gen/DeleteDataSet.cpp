
#include "gen/DeleteDataSet.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of DeleteDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const DeleteDataSet::CmdName = "DeleteDataSet";
    const char* const DeleteDataSet::Documentation = "Delete data set.";

    REGISTER_COMMAND_FACTORY(DeleteDataSet);


    DeleteDataSet::DeleteDataSet()
      : CommandBase(CmdName)
    {}

    DeleteDataSet::DeleteDataSet(const std::string& system, const std::string& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setDataSetName(dataSetName);
    }

    DeleteDataSetPtr DeleteDataSet::create(const std::string& system, const std::string& dataSetName)
    {
      return std::make_shared<DeleteDataSet>(system, dataSetName);
    }

    DeleteDataSetPtr DeleteDataSet::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<DeleteDataSet>(ptr);
    }

    bool DeleteDataSet::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string DeleteDataSet::documentation() const { return Documentation; }


    int DeleteDataSet::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string DeleteDataSet::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void DeleteDataSet::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string DeleteDataSet::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void DeleteDataSet::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
