/**
 * @file intt/InttHit.h
 * @author D. McGlinchey
 * @date June 2018
 * @brief Intt hit object
 */
#ifndef INTT_INTTHIT_H
#define INTT_INTTHIT_H

#include <trackbase/TrkrHit.h>

#include <iostream>

/**
 * @brief Intt hit object
 *
 * Container for Intt hit object representing
 * a single hit strip within a chip
 */
class InttHit : public TrkrHit
{
 public:
  //! ctor
  InttHit();
  //! dtor
  virtual ~InttHit(){};

  // PHObject virtual overloads
  virtual void identify(std::ostream& os = std::cout) const;
  virtual void Reset();
  virtual int isValid() const;

  //void addEnergy(const double edep) {m_edep += edep; std::cout << "added energy " << edep << " to InttHit" << std::endl;}
  //double getEnergy() const {return m_edep;}


  /**
   * @brief Set the ADC information
   * @param[in] adc ADC value
   */
  //void setAdc(const short adc) { m_adc = adc; }

  /**
   * @brief Get ADC value
   * @param[out] ADC value
   */
  //short getAdc() const { return m_adc; }

 private:
   //short m_adc;
   //double m_edep;
  ClassDef(InttHit, 1);
};

#endif  //INTT_INTTHIT_H
