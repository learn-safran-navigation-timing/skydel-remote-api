
#include "gen/GetPrnOfSVID.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnOfSVID
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnOfSVID::CmdName = "GetPrnOfSVID";
    const char* const GetPrnOfSVID::Documentation = "Get the PRN transmitted by the SV ID for this signal.";

    REGISTER_COMMAND_FACTORY(GetPrnOfSVID);


    GetPrnOfSVID::GetPrnOfSVID()
      : CommandBase(CmdName)
    {}

    GetPrnOfSVID::GetPrnOfSVID(const std::string& signal, int svId)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setSvId(svId);
    }

    GetPrnOfSVIDPtr GetPrnOfSVID::create(const std::string& signal, int svId)
    {
      return std::make_shared<GetPrnOfSVID>(signal, svId);
    }

    GetPrnOfSVIDPtr GetPrnOfSVID::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPrnOfSVID>(ptr);
    }

    bool GetPrnOfSVID::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetPrnOfSVID::documentation() const { return Documentation; }


    int GetPrnOfSVID::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPrnOfSVID::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPrnOfSVID::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPrnOfSVID::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPrnOfSVID::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
