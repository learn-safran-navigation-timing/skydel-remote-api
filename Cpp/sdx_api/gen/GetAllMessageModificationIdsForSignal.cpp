
#include "gen/GetAllMessageModificationIdsForSignal.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMessageModificationIdsForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMessageModificationIdsForSignal::CmdName = "GetAllMessageModificationIdsForSignal";
    const char* const GetAllMessageModificationIdsForSignal::Documentation = "Get all the message modification event's IDs for this signal and SV ID.";

    REGISTER_COMMAND_FACTORY(GetAllMessageModificationIdsForSignal);


    GetAllMessageModificationIdsForSignal::GetAllMessageModificationIdsForSignal()
      : CommandBase(CmdName)
    {}

    GetAllMessageModificationIdsForSignal::GetAllMessageModificationIdsForSignal(const std::string& signal, int svId)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setSvId(svId);
    }

    GetAllMessageModificationIdsForSignalPtr GetAllMessageModificationIdsForSignal::create(const std::string& signal, int svId)
    {
      return std::make_shared<GetAllMessageModificationIdsForSignal>(signal, svId);
    }

    GetAllMessageModificationIdsForSignalPtr GetAllMessageModificationIdsForSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMessageModificationIdsForSignal>(ptr);
    }

    bool GetAllMessageModificationIdsForSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetAllMessageModificationIdsForSignal::documentation() const { return Documentation; }


    int GetAllMessageModificationIdsForSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllMessageModificationIdsForSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetAllMessageModificationIdsForSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllMessageModificationIdsForSignal::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetAllMessageModificationIdsForSignal::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
