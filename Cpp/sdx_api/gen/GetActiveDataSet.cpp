
#include "gen/GetActiveDataSet.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetActiveDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetActiveDataSet::CmdName = "GetActiveDataSet";
    const char* const GetActiveDataSet::Documentation = "Get active data set.";

    REGISTER_COMMAND_FACTORY(GetActiveDataSet);


    GetActiveDataSet::GetActiveDataSet()
      : CommandBase(CmdName)
    {}

    GetActiveDataSet::GetActiveDataSet(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    GetActiveDataSetPtr GetActiveDataSet::create(const std::string& system)
    {
      return std::make_shared<GetActiveDataSet>(system);
    }

    GetActiveDataSetPtr GetActiveDataSet::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetActiveDataSet>(ptr);
    }

    bool GetActiveDataSet::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetActiveDataSet::documentation() const { return Documentation; }


    int GetActiveDataSet::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetActiveDataSet::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetActiveDataSet::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
