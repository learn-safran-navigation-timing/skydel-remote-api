
#include "GetPrnOfSVIDResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnOfSVIDResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnOfSVIDResult::CmdName = "GetPrnOfSVIDResult";
    const char* const GetPrnOfSVIDResult::Documentation = "Result of GetPrnOfSVID.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"NAVICL5\", \"PULSARXL\"\n"
      "SvId   int    Satellite SV ID.\n"
      "Prn    int    PRN number.";
    const char* const GetPrnOfSVIDResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPrnOfSVIDResult);


    GetPrnOfSVIDResult::GetPrnOfSVIDResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPrnOfSVIDResult::GetPrnOfSVIDResult(const std::string& signal, int svId, int prn)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setSvId(svId);
      setPrn(prn);
    }

    GetPrnOfSVIDResult::GetPrnOfSVIDResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, int prn)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignal(signal);
      setSvId(svId);
      setPrn(prn);
    }


    GetPrnOfSVIDResultPtr GetPrnOfSVIDResult::create(const std::string& signal, int svId, int prn)
    {
      return std::make_shared<GetPrnOfSVIDResult>(signal, svId, prn);
    }

    GetPrnOfSVIDResultPtr GetPrnOfSVIDResult::create(CommandBasePtr relatedCommand, const std::string& signal, int svId, int prn)
    {
      return std::make_shared<GetPrnOfSVIDResult>(relatedCommand, signal, svId, prn);
    }

    GetPrnOfSVIDResultPtr GetPrnOfSVIDResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPrnOfSVIDResult>(ptr);
    }

    bool GetPrnOfSVIDResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetPrnOfSVIDResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPrnOfSVIDResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SvId", "Prn"}; 
      return names; 
    }


    std::string GetPrnOfSVIDResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPrnOfSVIDResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPrnOfSVIDResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPrnOfSVIDResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPrnOfSVIDResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetPrnOfSVIDResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
