#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the error offset for a ionospheric grid point
    ///
    /// Name  Type Description
    /// ----- ---- -------------------------------
    /// Band  int  The ionospheric grid band index
    /// Point int  The IGP index
    ///

    class GetIonoGridError;
    typedef std::shared_ptr<GetIonoGridError> GetIonoGridErrorPtr;
    
    
    class GetIonoGridError : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoGridError();

      GetIonoGridError(int band, int point);

      static GetIonoGridErrorPtr create(int band, int point);
      static GetIonoGridErrorPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** band ****
      int band() const;
      void setBand(int band);


      // **** point ****
      int point() const;
      void setPoint(int point);
    };
    
  }
}

