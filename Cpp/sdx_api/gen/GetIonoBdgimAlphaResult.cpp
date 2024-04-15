
#include "GetIonoBdgimAlphaResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoBdgimAlphaResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoBdgimAlphaResult::CmdName = "GetIonoBdgimAlphaResult";
    const char* const GetIonoBdgimAlphaResult::Documentation = "Result of GetIonoBdgimAlpha.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------\n"
      "Index int    Coefficient index [1..9]\n"
      "Val   double Coefficient value";
    const char* const GetIonoBdgimAlphaResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoBdgimAlphaResult);


    GetIonoBdgimAlphaResult::GetIonoBdgimAlphaResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIonoBdgimAlphaResult::GetIonoBdgimAlphaResult(int index, double val)
      : CommandResult(CmdName, TargetId)
    {

      setIndex(index);
      setVal(val);
    }

    GetIonoBdgimAlphaResult::GetIonoBdgimAlphaResult(CommandBasePtr relatedCommand, int index, double val)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetIonoBdgimAlphaResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Index", "Val"}; 
      return names; 
    }


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
