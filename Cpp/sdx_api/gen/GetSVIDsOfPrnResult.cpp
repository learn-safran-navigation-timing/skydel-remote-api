
#include "GetSVIDsOfPrnResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVIDsOfPrnResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVIDsOfPrnResult::CmdName = "GetSVIDsOfPrnResult";
    const char* const GetSVIDsOfPrnResult::Documentation = "Result of GetSVIDsOfPrn.\n"
      "\n"
      "Name     Type      Description\n"
      "-------- --------- ----------------------------------------------------------------------\n"
      "Signal   string    Signal key - see GetSVIDsOfPrn command description for possible values\n"
      "Prn      int       Satellite PRN number\n"
      "SvIdList array int A list containing all SV ID of a specific signal";
    const char* const GetSVIDsOfPrnResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVIDsOfPrnResult);


    GetSVIDsOfPrnResult::GetSVIDsOfPrnResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSVIDsOfPrnResult::GetSVIDsOfPrnResult(const std::string& signal, int prn, const std::vector<int>& svIdList)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setPrn(prn);
      setSvIdList(svIdList);
    }

    GetSVIDsOfPrnResult::GetSVIDsOfPrnResult(CommandBasePtr relatedCommand, const std::string& signal, int prn, const std::vector<int>& svIdList)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignal(signal);
      setPrn(prn);
      setSvIdList(svIdList);
    }


    GetSVIDsOfPrnResultPtr GetSVIDsOfPrnResult::create(const std::string& signal, int prn, const std::vector<int>& svIdList)
    {
      return std::make_shared<GetSVIDsOfPrnResult>(signal, prn, svIdList);
    }

    GetSVIDsOfPrnResultPtr GetSVIDsOfPrnResult::create(CommandBasePtr relatedCommand, const std::string& signal, int prn, const std::vector<int>& svIdList)
    {
      return std::make_shared<GetSVIDsOfPrnResult>(relatedCommand, signal, prn, svIdList);
    }

    GetSVIDsOfPrnResultPtr GetSVIDsOfPrnResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVIDsOfPrnResult>(ptr);
    }

    bool GetSVIDsOfPrnResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::vector<int>>::is_valid(m_values["SvIdList"])
        ;

    }

    std::string GetSVIDsOfPrnResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSVIDsOfPrnResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Prn", "SvIdList"}; 
      return names; 
    }


    std::string GetSVIDsOfPrnResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetSVIDsOfPrnResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSVIDsOfPrnResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSVIDsOfPrnResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetSVIDsOfPrnResult::svIdList() const
    {
      return parse_json<std::vector<int>>::parse(m_values["SvIdList"]);
    }

    void GetSVIDsOfPrnResult::setSvIdList(const std::vector<int>& svIdList)
    {
      m_values.AddMember("SvIdList", parse_json<std::vector<int>>::format(svIdList, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
