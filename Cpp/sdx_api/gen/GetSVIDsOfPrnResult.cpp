
#include "gen/GetSVIDsOfPrnResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVIDsOfPrnResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVIDsOfPrnResult::CmdName = "GetSVIDsOfPrnResult";
    const char* const GetSVIDsOfPrnResult::Documentation = "Result of GetSVIDsOfPrn.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSVIDsOfPrnResult);


    GetSVIDsOfPrnResult::GetSVIDsOfPrnResult()
      : CommandResult(CmdName)
    {}

    GetSVIDsOfPrnResult::GetSVIDsOfPrnResult(const std::string& signal, int prn, const std::vector<int>& svIdList)
      : CommandResult(CmdName)
    {

      setSignal(signal);
      setPrn(prn);
      setSvIdList(svIdList);
    }

    GetSVIDsOfPrnResult::GetSVIDsOfPrnResult(CommandBasePtr relatedCommand, const std::string& signal, int prn, const std::vector<int>& svIdList)
      : CommandResult(CmdName, relatedCommand)
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
