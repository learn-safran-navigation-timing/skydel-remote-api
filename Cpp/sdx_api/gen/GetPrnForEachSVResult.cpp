
#include "GetPrnForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnForEachSVResult::CmdName = "GetPrnForEachSVResult";
    const char* const GetPrnForEachSVResult::Documentation = "Result of GetPrnForEachSV.\n"
      "\n"
      "Name   Type      Description\n"
      "------ --------- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Signal string    Accepted signal keys: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"
      "Prn    array int PRN value to set for each satellite. Zero based index (index 0 => PRN for SV ID 1, index 1 => PRN for SV ID 2, etc)";
    const char* const GetPrnForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPrnForEachSVResult);


    GetPrnForEachSVResult::GetPrnForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPrnForEachSVResult::GetPrnForEachSVResult(const std::string& signal, const std::vector<int>& prn)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setPrn(prn);
    }

    GetPrnForEachSVResult::GetPrnForEachSVResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& prn)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetPrnForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Prn"}; 
      return names; 
    }


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
