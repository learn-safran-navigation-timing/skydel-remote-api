#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Apply ranging flag for a SBAS satellite
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------
    /// Prn    int  The satellite's PRN number
    /// Health bool The ranging unhealthy flag
    ///

    class SetSbasHealthRanging;
    typedef std::shared_ptr<SetSbasHealthRanging> SetSbasHealthRangingPtr;
    
    
    class SetSbasHealthRanging : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasHealthRanging();

      SetSbasHealthRanging(int prn, bool health);
  
      static SetSbasHealthRangingPtr create(int prn, bool health);
      static SetSbasHealthRangingPtr dynamicCast(CommandBasePtr ptr);
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

