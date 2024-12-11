
#include "GetSVIDsOfPrn.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVIDsOfPrn
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVIDsOfPrn::CmdName = "GetSVIDsOfPrn";
    const char* const GetSVIDsOfPrn::Documentation = "Mapping PRN to the corresponding SV ID. Get a list of SV IDs based on a specific signal. Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", and \"PULSARXL\", \"PULSARX1\"\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------\n"
      "Signal string Signal key - see GetSVIDsOfPrn command description for possible values\n"
      "Prn    int    Satellite PRN number";
    const char* const GetSVIDsOfPrn::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSVIDsOfPrn);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVIDsOfPrn);


    GetSVIDsOfPrn::GetSVIDsOfPrn()
      : CommandBase(CmdName, TargetId)
    {}

    GetSVIDsOfPrn::GetSVIDsOfPrn(const std::string& signal, int prn)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetSVIDsOfPrn::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Prn"}; 
      return names; 
    }


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
