
#include "GetActiveDataSet.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetActiveDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetActiveDataSet::CmdName = "GetActiveDataSet";
    const char* const GetActiveDataSet::Documentation = "Get active data set.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------\n"
      "System string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const GetActiveDataSet::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetActiveDataSet);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetActiveDataSet);


    GetActiveDataSet::GetActiveDataSet()
      : CommandBase(CmdName, TargetId)
    {}

    GetActiveDataSet::GetActiveDataSet(const std::string& system)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetActiveDataSet::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int GetActiveDataSet::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
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
