#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the error offset for a ionospheric grid point
    ///
    /// Name  Type   Description
    /// ----- ------ -------------------------------
    /// Band  int    The ionospheric grid band index
    /// Point int    The IGP index
    /// Error double The error offset at the IGP
    ///

    class SetIonoGridError;
    typedef std::shared_ptr<SetIonoGridError> SetIonoGridErrorPtr;
    
    
    class SetIonoGridError : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIonoGridError();

      SetIonoGridError(int band, int point, double error);

      static SetIonoGridErrorPtr create(int band, int point, double error);
      static SetIonoGridErrorPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** band ****
      int band() const;
      void setBand(int band);


      // **** point ****
      int point() const;
      void setPoint(int point);


      // **** error ****
      double error() const;
      void setError(double error);
    };
    
  }
}

