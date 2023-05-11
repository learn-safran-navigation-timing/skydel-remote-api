#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the BeiDou (BDGIM) ionospheric Alpha coefficient (in TECu)
    ///
    /// Name  Type Description
    /// ----- ---- ------------------------
    /// Index int  Coefficient index [1..9]
    ///

    class GetIonoBdgimAlpha;
    typedef std::shared_ptr<GetIonoBdgimAlpha> GetIonoBdgimAlphaPtr;
    
    
    class GetIonoBdgimAlpha : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoBdgimAlpha();

      GetIonoBdgimAlpha(int index);

      static GetIonoBdgimAlphaPtr create(int index);
      static GetIonoBdgimAlphaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** index ****
      int index() const;
      void setIndex(int index);
    };
    
  }
}

