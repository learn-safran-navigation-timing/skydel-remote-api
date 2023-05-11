
#include "gen/GetIonoBdgimAlphaResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoBdgimAlphaResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoBdgimAlphaResult::CmdName = "GetIonoBdgimAlphaResult";
    const char* const GetIonoBdgimAlphaResult::Documentation = "Result of GetIonoBdgimAlpha.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIonoBdgimAlphaResult);


    GetIonoBdgimAlphaResult::GetIonoBdgimAlphaResult()
      : CommandResult(CmdName)
    {}

    GetIonoBdgimAlphaResult::GetIonoBdgimAlphaResult(int index, double val)
      : CommandResult(CmdName)
    {

      setIndex(index);
      setVal(val);
    }

    GetIonoBdgimAlphaResult::GetIonoBdgimAlphaResult(CommandBasePtr relatedCommand, int index, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setIndex(index);
      setVal(val);
    }


    GetIonoBdgimAlphaResultPtr GetIonoBdgimAlphaResult::create(int index, double val)
    {
      return std::make_shared<GetIonoBdgimAlphaResult>(index, val);
    }

    GetIonoBdgimAlphaResultPtr GetIonoBdgimAlphaResult::create(CommandBasePtr relatedCommand, int index, double val)
    {
      return std::make_shared<GetIonoBdgimAlphaResult>(relatedCommand, index, val);
    }

    GetIonoBdgimAlphaResultPtr GetIonoBdgimAlphaResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoBdgimAlphaResult>(ptr);
    }

    bool GetIonoBdgimAlphaResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetIonoBdgimAlphaResult::documentation() const { return Documentation; }


    int GetIonoBdgimAlphaResult::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void GetIonoBdgimAlphaResult::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIonoBdgimAlphaResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetIonoBdgimAlphaResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
