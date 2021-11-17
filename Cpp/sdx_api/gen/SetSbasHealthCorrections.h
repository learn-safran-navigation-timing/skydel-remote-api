#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetSbasHealthCorrections is deprecated since 21.9. You may use SetSbasSVCorrectionsHealth.
    /// 
    /// Apply correction flag for a SBAS satellite
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------
    /// Prn    int  The satellite's PRN number
    /// Health bool The correction unhealthy flag
    ///

    class SetSbasHealthCorrections;
    typedef std::shared_ptr<SetSbasHealthCorrections> SetSbasHealthCorrectionsPtr;
    
    
    class SetSbasHealthCorrections : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasHealthCorrections();

      SetSbasHealthCorrections(int prn, bool health);
  
      static SetSbasHealthCorrectionsPtr create(int prn, bool health);
      static SetSbasHealthCorrectionsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

