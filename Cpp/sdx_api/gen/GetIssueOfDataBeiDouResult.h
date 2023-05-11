#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIssueOfDataBeiDou.
    ///
    /// Name      Type Description
    /// --------- ---- ------------------------
    /// Clock     int  Issue of data, clock
    /// Ephemeris int  Issue of data, ephemeris
    ///

    class GetIssueOfDataBeiDouResult;
    typedef std::shared_ptr<GetIssueOfDataBeiDouResult> GetIssueOfDataBeiDouResultPtr;
    
    
    class GetIssueOfDataBeiDouResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIssueOfDataBeiDouResult();

      GetIssueOfDataBeiDouResult(int clock, int ephemeris);

      GetIssueOfDataBeiDouResult(CommandBasePtr relatedCommand, int clock, int ephemeris);

      static GetIssueOfDataBeiDouResultPtr create(int clock, int ephemeris);

      static GetIssueOfDataBeiDouResultPtr create(CommandBasePtr relatedCommand, int clock, int ephemeris);
      static GetIssueOfDataBeiDouResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** clock ****
      int clock() const;
      void setClock(int clock);


      // **** ephemeris ****
      int ephemeris() const;
      void setEphemeris(int ephemeris);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIssueOfDataBeiDouResult);
  }
}

