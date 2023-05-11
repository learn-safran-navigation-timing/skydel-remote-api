
#include "gen/SetPrnOfSVID.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPrnOfSVID
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPrnOfSVID::CmdName = "SetPrnOfSVID";
    const char* const SetPrnOfSVID::Documentation = "Set the PRN transmitted by the SV ID for this signal.";

    REGISTER_COMMAND_FACTORY(SetPrnOfSVID);


    SetPrnOfSVID::SetPrnOfSVID()
      : CommandBase(CmdName)
    {}

    SetPrnOfSVID::SetPrnOfSVID(const std::string& signal, int svId, int prn)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setSvId(svId);
      setPrn(prn);
    }

    SetPrnOfSVIDPtr SetPrnOfSVID::create(const std::string& signal, int svId, int prn)
    {
      return std::make_shared<SetPrnOfSVID>(signal, svId, prn);
    }

    SetPrnOfSVIDPtr SetPrnOfSVID::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPrnOfSVID>(ptr);
    }

    bool SetPrnOfSVID::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string SetPrnOfSVID::documentation() const { return Documentation; }


    int SetPrnOfSVID::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPrnOfSVID::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetPrnOfSVID::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPrnOfSVID::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPrnOfSVID::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPrnOfSVID::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetPrnOfSVID::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
