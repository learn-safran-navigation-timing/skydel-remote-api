
#include "gen/SetActiveDataSet.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetActiveDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetActiveDataSet::CmdName = "SetActiveDataSet";
    const char* const SetActiveDataSet::Documentation = "Set active data set.";

    REGISTER_COMMAND_FACTORY(SetActiveDataSet);


    SetActiveDataSet::SetActiveDataSet()
      : CommandBase(CmdName)
    {}

    SetActiveDataSet::SetActiveDataSet(const std::string& system, const std::string& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setDataSetName(dataSetName);
    }

    SetActiveDataSetPtr SetActiveDataSet::create(const std::string& system, const std::string& dataSetName)
    {
      return std::make_shared<SetActiveDataSet>(system, dataSetName);
    }

    SetActiveDataSetPtr SetActiveDataSet::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetActiveDataSet>(ptr);
    }

    bool SetActiveDataSet::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetActiveDataSet::documentation() const { return Documentation; }


    int SetActiveDataSet::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string SetActiveDataSet::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetActiveDataSet::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetActiveDataSet::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void SetActiveDataSet::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
