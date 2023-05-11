
#include "gen/GetPrnForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnForEachSVResult::CmdName = "GetPrnForEachSVResult";
    const char* const GetPrnForEachSVResult::Documentation = "Result of GetPrnForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetPrnForEachSVResult);


    GetPrnForEachSVResult::GetPrnForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetPrnForEachSVResult::GetPrnForEachSVResult(const std::string& signal, const std::vector<int>& prn)
      : CommandResult(CmdName)
    {

      setSignal(signal);
      setPrn(prn);
    }

    GetPrnForEachSVResult::GetPrnForEachSVResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& prn)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setPrn(prn);
    }


    GetPrnForEachSVResultPtr GetPrnForEachSVResult::create(const std::string& signal, const std::vector<int>& prn)
    {
      return std::make_shared<GetPrnForEachSVResult>(signal, prn);
    }

    GetPrnForEachSVResultPtr GetPrnForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& prn)
    {
      return std::make_shared<GetPrnForEachSVResult>(relatedCommand, signal, prn);
    }

    GetPrnForEachSVResultPtr GetPrnForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPrnForEachSVResult>(ptr);
    }

    bool GetPrnForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<int>>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetPrnForEachSVResult::documentation() const { return Documentation; }


    std::string GetPrnForEachSVResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPrnForEachSVResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetPrnForEachSVResult::prn() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Prn"]);
    }

    void GetPrnForEachSVResult::setPrn(const std::vector<int>& prn)
    {
      m_values.AddMember("Prn", parse_json<std::vector<int>>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
