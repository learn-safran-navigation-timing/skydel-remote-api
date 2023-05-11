#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set BeiDou Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
    ///
    /// Name      Type Description
    /// --------- ---- ------------------------
    /// Clock     int  Issue of data, clock
    /// Ephemeris int  Issue of data, ephemeris
    ///

    class SetIssueOfDataBeiDou;
    typedef std::shared_ptr<SetIssueOfDataBeiDou> SetIssueOfDataBeiDouPtr;
    
    
    class SetIssueOfDataBeiDou : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIssueOfDataBeiDou();

      SetIssueOfDataBeiDou(int clock, int ephemeris);

      static SetIssueOfDataBeiDouPtr create(int clock, int ephemeris);
      static SetIssueOfDataBeiDouPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** clock ****
      int clock() const;
      void setClock(int clock);


      // **** ephemeris ****
      int ephemeris() const;
      void setEphemeris(int ephemeris);
    };
    
  }
}

