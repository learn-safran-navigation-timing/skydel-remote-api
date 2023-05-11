
#include "gen/GetSVIDsOfPrn.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVIDsOfPrn
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVIDsOfPrn::CmdName = "GetSVIDsOfPrn";
    const char* const GetSVIDsOfPrn::Documentation = "Mapping PRN to the corresponding SV ID. Get a list of SV IDs based on a specific signal. Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\" and \"NAVICL5\"";

    REGISTER_COMMAND_FACTORY(GetSVIDsOfPrn);


    GetSVIDsOfPrn::GetSVIDsOfPrn()
      : CommandBase(CmdName)
    {}

    GetSVIDsOfPrn::GetSVIDsOfPrn(const std::string& signal, int prn)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setPrn(prn);
    }

    GetSVIDsOfPrnPtr GetSVIDsOfPrn::create(const std::string& signal, int prn)
    {
      return std::make_shared<GetSVIDsOfPrn>(signal, prn);
    }

    GetSVIDsOfPrnPtr GetSVIDsOfPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVIDsOfPrn>(ptr);
    }

    bool GetSVIDsOfPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetSVIDsOfPrn::documentation() const { return Documentation; }


    int GetSVIDsOfPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSVIDsOfPrn::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetSVIDsOfPrn::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSVIDsOfPrn::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSVIDsOfPrn::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
