
#include "GetMainInstanceStatusResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMainInstanceStatusResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMainInstanceStatusResult::CmdName = "GetMainInstanceStatusResult";
    const char* const GetMainInstanceStatusResult::Documentation = "Result of GetMainInstanceStatus.\n"
      "\n"
      "Name                    Type Description\n"
      "----------------------- ---- --------------------------------------------\n"
      "IsMainInstance          bool True if Skydel is in main instance mode\n"
      "WorkerInstanceConnected int  The number of connected worker instances\n"
      "Port                    int  The listening port, 0 if not a main instance";
    const char* const GetMainInstanceStatusResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMainInstanceStatusResult);


    GetMainInstanceStatusResult::GetMainInstanceStatusResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetMainInstanceStatusResult::GetMainInstanceStatusResult(bool isMainInstance, int workerInstanceConnected, int port)
      : CommandResult(CmdName, TargetId)
    {

      setIsMainInstance(isMainInstance);
      setWorkerInstanceConnected(workerInstanceConnected);
      setPort(port);
    }

    GetMainInstanceStatusResult::GetMainInstanceStatusResult(CommandBasePtr relatedCommand, bool isMainInstance, int workerInstanceConnected, int port)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIsMainInstance(isMainInstance);
      setWorkerInstanceConnected(workerInstanceConnected);
      setPort(port);
    }


    GetMainInstanceStatusResultPtr GetMainInstanceStatusResult::create(bool isMainInstance, int workerInstanceConnected, int port)
    {
      return std::make_shared<GetMainInstanceStatusResult>(isMainInstance, workerInstanceConnected, port);
    }

    GetMainInstanceStatusResultPtr GetMainInstanceStatusResult::create(CommandBasePtr relatedCommand, bool isMainInstance, int workerInstanceConnected, int port)
    {
      return std::make_shared<GetMainInstanceStatusResult>(relatedCommand, isMainInstance, workerInstanceConnected, port);
    }

    GetMainInstanceStatusResultPtr GetMainInstanceStatusResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMainInstanceStatusResult>(ptr);
    }

    bool GetMainInstanceStatusResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsMainInstance"])
          && parse_json<int>::is_valid(m_values["WorkerInstanceConnected"])
          && parse_json<int>::is_valid(m_values["Port"])
        ;

    }

    std::string GetMainInstanceStatusResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMainInstanceStatusResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsMainInstance", "WorkerInstanceConnected", "Port"}; 
      return names; 
    }


    bool GetMainInstanceStatusResult::isMainInstance() const
    {
      return parse_json<bool>::parse(m_values["IsMainInstance"]);
    }

    void GetMainInstanceStatusResult::setIsMainInstance(bool isMainInstance)
    {
      m_values.AddMember("IsMainInstance", parse_json<bool>::format(isMainInstance, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMainInstanceStatusResult::workerInstanceConnected() const
    {
      return parse_json<int>::parse(m_values["WorkerInstanceConnected"]);
    }

    void GetMainInstanceStatusResult::setWorkerInstanceConnected(int workerInstanceConnected)
    {
      m_values.AddMember("WorkerInstanceConnected", parse_json<int>::format(workerInstanceConnected, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMainInstanceStatusResult::port() const
    {
      return parse_json<int>::parse(m_values["Port"]);
    }

    void GetMainInstanceStatusResult::setPort(int port)
    {
      m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
