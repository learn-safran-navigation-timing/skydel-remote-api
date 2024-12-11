
#include "SetPrnOfSVID.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPrnOfSVID
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPrnOfSVID::CmdName = "SetPrnOfSVID";
    const char* const SetPrnOfSVID::Documentation = "Set the PRN transmitted by the SV ID for this signal.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\"\n"
      "SvId   int    Satellite SV ID.\n"
      "Prn    int    PRN number.";
    const char* const SetPrnOfSVID::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPrnOfSVID);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPrnOfSVID);


    SetPrnOfSVID::SetPrnOfSVID()
      : CommandBase(CmdName, TargetId)
    {}

    SetPrnOfSVID::SetPrnOfSVID(const std::string& signal, int svId, int prn)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetPrnOfSVID::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SvId", "Prn"}; 
      return names; 
    }


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
